#!/bin/bash
MYPATH="$(readlink -f -- "${0}")"
APPDIR="$(dirname "${MYPATH}")"
APPNAME="$(basename "${MYPATH}" ".sh")"
export NV_AGORA_PATH="${APPDIR}"
export LD_LIBRARY_PATH="${NV_AGORA_PATH}:${LD_LIBRARY_PATH}"

"${NV_AGORA_PATH}/${APPNAME}" "${@}"
