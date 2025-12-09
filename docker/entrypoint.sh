#!/bin/bash

# ========================================================================
# CoreX Zephyr Development Container Entrypoint
# ========================================================================


set -e

USER="jmendes"

{
  echo "alias monitor=\"sudo minicom -D /dev/ttyACM1 -b 115200\""
} >> /home/$USER/.bashrc

exec "$@"
