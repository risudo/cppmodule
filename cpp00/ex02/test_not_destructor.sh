diff -y <(cat 19920104_091532.log | cut -d " " -f 2 | grep -v "close") <(./a.out | cut -d " " -f 2 | grep -v "close")
