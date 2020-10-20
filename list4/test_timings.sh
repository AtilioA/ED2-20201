#! /bin/bash

count=0
repeticoes=5000
echo -e "Testando $1:\n"

TIMEFORMAT="$1: nearly_sorted 100000: %R segundos"
time {
    while [[ count -lt repeticoes ]]; do
        ($2) < nearly_sorted/100000.txt
        count=$(expr $count + 1)
    done
}
echo -e "($repeticoes repeticoes)"
count=0

TIMEFORMAT="$1: nearly_sorted 1000000: %R segundos"
time {
    while [[ count -lt repeticoes ]]; do
        ($2) < nearly_sorted/100000.txt
        count=$(expr $count + 1)
    done
}
echo -e "($repeticoes repeticoes)"
count=0

TIMEFORMAT="$1: reverse_sorted 100000: %R segundos"
time {
    while [[ count -lt repeticoes ]]; do
        ($2) < reverse_sorted/100000.txt
        count=$(expr $count + 1)
    done
}
echo -e "($repeticoes repeticoes)"
count=0

TIMEFORMAT="$1: reverse_sorted 1000000: %R segundos"
time {
    while [[ count -lt repeticoes ]]; do
        ($2) < reverse_sorted/1000000.txt
        count=$(expr $count + 1)
    done
}
echo -e "($repeticoes repeticoes)"
count=0

TIMEFORMAT="$1: sorted 100000: %R segundos"
time {
    while [[ count -lt repeticoes ]]; do
        ($2) < sorted/100000.txt
        count=$(expr $count + 1)
    done
}
echo -e "($repeticoes repeticoes)"
count=0

TIMEFORMAT="$1: sorted 1000000: %R segundos"
time {
    while [[ count -lt repeticoes ]]; do
        ($2) < sorted/1000000.txt
        count=$(expr $count + 1)
    done
}
echo -e "($repeticoes repeticoes)"
count=0

TIMEFORMAT="$1: unif_rand 100000: %R segundos"
time {
    while [[ count -lt repeticoes ]]; do
        ($2) < unif_rand/100000.txt
        count=$(expr $count + 1)
    done
}
echo -e "($repeticoes repeticoes)"
count=0

TIMEFORMAT="$1: unif_rand 1000000: %R segundos"
time {
    while [[ count -lt repeticoes ]]; do
        ($2) < unif_rand/1000000.txt
        count=$(expr $count + 1)
    done
}
echo -e "($repeticoes repeticoes)\n"
