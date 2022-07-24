# Script to spread built package to all cluster nodes
# Note: set resources/config/cluster_ips first

# import util
util_path=$(dirname "$0")"/util.sh"
source "$util_path"

# 1. organize executables, resources and required libraries
rm -rf "$deploy_dir"
echo "Copying built files..."
mkdir -p "$deploy_dir"

# executables
exe_dir="$build_dir"/"$exe_dir_name"
exe_deploy_dir="$deploy_dir"/"$exe_dir_name"
cp -r "$exe_dir"/ "$exe_deploy_dir"/

# calcite
calcite_jar_path="$root_dir"/"$calcite_dir_name""/target/""$calcite_jar_name"
calcite_deploy_jar_path="$deploy_dir"/"$calcite_dir_name""/target/""$calcite_jar_name"
mkdir -p "$(dirname "${calcite_deploy_jar_path}")"
cp -r "$calcite_jar_path" "$calcite_deploy_jar_path"

# resources
resource_deploy_dir="$deploy_dir""/resources/"
mkdir -p "$(dirname "${resource_deploy_dir}")"
cp -r "$resource_dir"/ "$resource_deploy_dir"/

