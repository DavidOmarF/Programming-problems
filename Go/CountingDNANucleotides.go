package main

import (
	"bufio"
	"fmt"
	"os"
)

func readFile(lineNumber int) string {
	f, _ := os.Open("test.txt")
	scanner := bufio.NewScanner(f)
	var line string
	i := 0
	for scanner.Scan() {
		if i == lineNumber {
			line = scanner.Text()
			break
		} else {
			i++
		}

	}
	return line
}

func main() {
	dnaString := []byte(readFile(0))
	t := [4]int{0, 0, 0, 0}
	i := 0
	for ; i < len(dnaString); i++ {
		if dnaString[i] == 'A' {
			t[0]++
		} else if dnaString[i] == 'C' {
			t[1]++
		} else if dnaString[i] == 'G' {
			t[2]++
		} else if dnaString[i] == 'T' {
			t[3]++
		}
	}
	fmt.Println(t)
}
