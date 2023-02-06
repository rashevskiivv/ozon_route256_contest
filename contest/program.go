package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		var k int
		fmt.Fscan(in, &k)
		arr := make([]int, k)
		for j := 0; j < k; j++ {
			var buf int
			fmt.Fscan(in, &buf)
			arr = append(arr, buf)
		}
		fmt.Fprintln(out, arr)
	}
}
