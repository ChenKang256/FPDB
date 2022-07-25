import os
import numpy as np
import sys

lines_containing_metrics = [
    { "name": "Total Execution Time", "indices": [3]},
    { "name": "FileScanPOp", "indices": [1, 3]},
    { "name": "FilterPOp", "indices": [1, 3]}
]

metric_dict = {}
run_prefix = ""
metric_prefix = "tpch/original/"
base_dir = "/mnt/Work/FlexPushdownDB-Dev/"

def parse_metrics():
    metrics_directory = base_dir + "build/fpdb-main/metrics/" + run_prefix
    all_dirs = sorted(os.listdir(metrics_directory))
    for metrics_folder_ts in all_dirs[1:]:
        metrics_folder = os.path.join(metrics_directory, metrics_folder_ts)
        actual_metrics_folder = os.path.join(metrics_folder, metric_prefix)
        for file in os.listdir(actual_metrics_folder):
            if file.endswith(".txt"):
                query_name = int(file.split(".")[0])
                metric_d = metric_dict.get(query_name, {})
                with open(actual_metrics_folder + file, "r") as f:
                    for line in f:
                        for metric in lines_containing_metrics:
                            if metric["name"] in line:
                                to_write = [x for x in line.split(" ") if len(x) > 0]
                                cols_to_write = [float(to_write[i]) for i in metric["indices"]]
                                if metric["name"] not in metric_d:
                                    metric_d[metric["name"]] = []
                                metric_d[metric["name"]].append(cols_to_write)
                
                metric_dict[query_name] = metric_d


cols = ["Query", "Total Execution Time (ms)", "FileScanPOp (sec)", "FileScanPOp (% Total Time)", "FilterPOp (sec)", "FilterPOp (% Total Time)"]


def main():
    parse_metrics()
    output_file_name = base_dir + "results/%s_output.csv" % run_prefix
    # make directory if it doesn't exist
    if not os.path.exists(os.path.dirname(output_file_name)):
        try:
            os.makedirs(os.path.dirname(output_file_name))
        except OSError as exc:
            print("Error creating directory: %s" % exc)
            sys.exit(1)
            
    output_file = open(output_file_name, "w")
    output_file.write(",".join(cols) + "\n")
    for metric_d in sorted(metric_dict.keys()):
        str_to_write = str(metric_d) + ","
        for metric in metric_dict[metric_d]:
            vals = np.mean(metric_dict[metric_d][metric], axis = 0)
            for val in vals:
                str_to_write += "%.2f" % val + ","
        str_to_write = str_to_write[:-1] + "\n"
        output_file.write(str_to_write)
    
    output_file.close()



if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python parse_metrics.py <metric_prefix>")
        exit(1)
    run_prefix = sys.argv[1]
    main()
