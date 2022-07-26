# Put this under ssb-dbgen/
# Make sure dbgen has been built, to build it, do as follows:
#   1) git clone https://github.com/electrum/ssb-dbgen.git
#   2) run 'make' inside the repo

import os
import platform
import math
import threading
import sys

# configurable parameters
if len(sys.argv) < 2:
    print("Usage: {} <scale_factor>".format(sys.argv[0]))
    exit(1)

sf = sys.argv[1]
support_sf = ['1', '10', '20', '30', '100']

num_partitions_dict = {
    '1': {
        'part': 1,
        'supplier': 1,
        'customer': 1,
        'date': 1,
        'lineorder': 32
    },
    '10': {
        'part': 6,
        'supplier': 1,
        'customer': 2,
        'date': 1,
        'lineorder': 400
    }, 
    '20': {
        'part': 7,
        'supplier': 1,
        'customer': 4,
        'date': 1,
        'lineorder': 800
    }, 
    '30': {
        'part': 8,
        'supplier': 1,
        'customer': 6,
        'date': 1,
        'lineorder': 1200
    }, 
    '100': {
        'part': 10,
        'supplier': 1,
        'customer': 20,
        'date': 1,
        'lineorder': 4001
    }
}


def get_num_lines_partition(num_lines, num_partitions):
    return int(math.ceil(float(num_lines) / float(num_partitions)))


def get_num_digits_suffix(num_partitions):
    return int(math.ceil(math.log(num_partitions, 10)))


def run_command(cmd):
    os.system(cmd)


def format_data_for_table(table, column_names, num_partitions):
    global split_func, data_dir

    table_file = table + ".tbl"
    partition_file_prefix = table_file + "."
    partition_dir = table + "_sharded"

    # remove '|' at the end of each row
    if platform.system() == "Darwin":
        os.system('sed -i \'\' \'s/.$//\' {}'.format(table_file))
    else:
        os.system('sed -i \'s/.$//\' {}'.format(table_file))

    # split table file if it has multiple partitions
    if num_partitions > 1:
        # get num of lines
        num_lines = int(os.popen('wc -l < {}'.format(table_file)).read())

        # split table into partitions
        num_lines_partition = get_num_lines_partition(num_lines, num_partitions)
        num_digits_suffix = get_num_digits_suffix(num_partitions)
        os.system('{} -a {} -d -l {} {} {}'.format(split_func,
                                                   num_digits_suffix,
                                                   num_lines_partition,
                                                   table_file,
                                                   partition_file_prefix))

        # remove leading 0s in the suffix of partitions and add column names
        threads = []
        for i in range(num_partitions):
            old_name = partition_file_prefix + str(i).zfill(num_digits_suffix)
            new_name = partition_file_prefix + str(i)
            os.system('mv {} {} 2>/dev/null'.format(old_name, new_name))

            if platform.system() == "Darwin":
                cmd_add_column_names = 'sed -i \'\' \'1s/^/{}\\\'$\'\\n/\' {}'.format(column_names, new_name)
            else:
                cmd_add_column_names = 'sed -i \'1i {}\' {}'.format(column_names, new_name)
            t = threading.Thread(target=run_command, args=(cmd_add_column_names,))
            t.start()
            threads.append(t)
        for t in threads:
            t.join()

        # move partitions into the directory
        os.system('mkdir {}'.format(partition_dir))
        os.system('mv {}* {}/'.format(partition_file_prefix, partition_dir))

        # move data into data_dir
        os.system('mv {} {}'.format(partition_dir, data_dir))

    else:
        # add column names
        if platform.system() == "Darwin":
            os.system('sed -i \'\' \'1s/^/{}\\\'$\'\\n/\' {}'.format(column_names, table_file))
        else:
            os.system('sed -i \'1i {}\' {}'.format(column_names, table_file))

        # move data into data_dir
        os.system('mv {} {}'.format(table_file, data_dir))


# fixed parameters
tables = ['part', 'supplier', 'customer', 'date', 'lineorder']
tables_sur = ['c', 'p', 's', 'd', 'l']
column_names_dict = {
    'part': 'P_PARTKEY|P_NAME|P_MFGR|P_CATEGORY|P_BRAND1|P_COLOR|P_TYPE|P_SIZE|P_CONTAINER',
    'supplier': 'S_SUPPKEY|S_NAME|S_ADDRESS|S_CITY|S_NATION|S_REGION|S_PHONE',
    'customer': 'C_CUSTKEY|C_NAME|C_ADDRESS|C_CITY|C_NATION|C_REGION|C_PHONE|C_MKTSEGMENT',
    'date': 'D_DATEKEY|D_DATE|D_DAYOFWEEK|D_MONTH|D_YEAR|D_YEARMONTHNUM|D_YEARMONTH|D_DAYNUMINWEEK|D_DAYNUMINMONTH|D_DAYNUMINYEAR|D_MONTHNUMINYEAR|D_WEEKNUMINYEAR|D_SELLINGSEASON|D_LASTDAYINWEEKFL|D_LASTDAYINMONTHFL|D_HOLIDAYFL|D_WEEKDAYFL',
    'lineorder': 'LO_ORDERKEY|LO_LINENUMBER|LO_CUSTKEY|LO_PARTKEY|LO_SUPPKEY|LO_ORDERDATE|LO_ORDERPRIORITY|LO_SHIPPRIORITY|LO_QUANTITY|LO_EXTENDEDPRICE|LO_ORDTOTALPRICE|LO_DISCOUNT|LO_REVENUE|LO_SUPPLYCOST|LO_TAX|LO_COMMITDATE|LO_SHIPMODE'
}

# pick appropriate split tool
if platform.system() == "Darwin":
    split_func = "gsplit"
else:
    split_func = "split"

# check if supported
if sf not in support_sf:
    raise Exception("Unsupported scale factor {}, only support {}".format(sf, str(support_sf)))

# create the directory to put data
data_dir = 'data/ssb-sf' + str(sf)
os.system('rm -rf {}'.format(data_dir))
os.system('mkdir -p {}'.format(data_dir))

# generate data
for sur in tables_sur:
    os.system('./dbgen -s {} -T {}'.format(float(sf), sur))
full_path = os.path.abspath(os.path.dirname(data_dir))
print("Tables generated at {}".format(full_path))

# format for each table
for table in tables:
    print("Formatting " + table + "... ", end='', flush=True)
    format_data_for_table(table, column_names_dict[table], num_partitions_dict[sf][table])
    print('done')
print("Tables formatted.")

os.system('rm -f *.tbl')
