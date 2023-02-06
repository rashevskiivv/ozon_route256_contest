package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solution(in *bufio.Reader, out *bufio.Writer) {
	var kStr string
	fmt.Fscan(in, &kStr)
	k, _ := strconv.Atoi(strings.TrimSpace(kStr))

	var arrStr string
	fmt.Fscan(in, &arrStr)
	arr := strings.Split(strings.TrimSpace(arrStr), ",")

	used := make(map[int]int, 105)
	for _, x := range arr {
		if strings.Contains(x, "-") {
			lR := strings.Split(x, "-")
			l, _ := strconv.Atoi(lR[0])
			r, _ := strconv.Atoi(lR[1])

			for i := l; i <= r; i++ {
				used[i] = 1
			}
		} else {
			value, _ := strconv.Atoi(x)
			used[value] = 1
		}
	}

	used[0] = 1
	used[k+1] = 1

	var ans [][]int
	var cur []int
	for i := 1; i < k+2; i++ {
		if used[i] == 1 && used[i-1] == 0 {
			ans = append(ans, cur)
			cur = nil
		}

		if used[i] == 0 {
			cur = append(cur, i)
		}
	}

	length := len(ans)
	for i, pair := range ans {
		l, r := pair[0], pair[len(pair)-1]
		if l == r {
			fmt.Fprint(out, l)
		} else {
			fmt.Fprint(out, l, "-", r)
		}
		if i != length-1 {
			fmt.Fprint(out, ",")
		} else {
			fmt.Fprintln(out, "")
		}
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var tStr string
	fmt.Fscan(in, &tStr)
	t, _ := strconv.Atoi(strings.TrimSpace(tStr))
	for i := 0; i < t; i++ {
		solution(in, out)
	}
}
