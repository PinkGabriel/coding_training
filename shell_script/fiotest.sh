#!/bin/sh
#
# fio.sh fiofile.fio begintime(xx:xx,hour:minute) intervaltime(minute) result_num
#
# $1:fio conf file s2:job begintime s3:time for each job
#

type=r
num=2

at $2 <<EOF
fio $1 --output 3vm_${type}_result$num
EOF

at $2 + $3 minutes <<EOF
fio $1 --output 6vm_${type}_result$num
EOF

at $2 + $[2 * $3] minutes <<EOF
fio $1 --output 9vm_${type}_result$num
EOF

