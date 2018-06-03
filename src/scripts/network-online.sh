PING_URL="www.google.com"

ping -c 1 "${PING_URL}" >/dev/null 2>&1
exit "$?"