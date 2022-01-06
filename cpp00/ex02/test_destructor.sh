diff -y <(cat 19920104_091532.log | cut -d " " -f 2 | grep "close") <(./a.out | cut -d " " -f 2 | grep "close" | sort)
