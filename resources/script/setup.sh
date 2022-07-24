# main entry to setup the system on a cluster

# import util
util_path=$(dirname "$0")"/util.sh"
source "$util_path"

# install dependencies
if [ "$install_dependency" = true ]; then
  if [ "$(uname)" = "Darwin" ]; then
    # mac OS
    echo "Warning: automatically installing dependencies on Mac OS is unsupported."
  elif [ "$(expr substr "$(uname -s)" 1 5)" == "Linux" ]; then
    # linux
    if [  -n "$(uname -a | grep Ubuntu)" ]; then
      # ubuntu
      source "$root_dir""/tools/project/bin/ubuntu-prerequisites.sh"
    else
      echo "Warning: automatically installing dependencies on Linux which is not Ubuntu is unsupported."
    fi
  else
    echo "*** Error: supported OS are Mac OS or Linux."
    exit 0
  fi
fi

# build
bash "$script_dir"/build.sh -d
err_code=$?
if [ "$err_code" != 0 ]; then
  echo "*** Error: build failed."
  exit $err_code
fi

# deploy
bash "$script_dir"/deploy.sh
