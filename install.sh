#!/usr/bin/env bash
set -euo pipefail

git clone https://github.com/Serralq/algo-prog2.git
curl --proto '=https' --tlsv1.2 -sSf -L https://install.determinate.systems/nix | sh -s -- install --no-confirm
. /nix/var/nix/profiles/default/etc/profile.d/nix-daemon.sh
cd algo-prog2
nix-shell --pure --run "./test.sh"
