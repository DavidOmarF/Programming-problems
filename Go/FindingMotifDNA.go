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
	dnaString2 := []byte(readFile(1))
	if len(dnaString) < len(dnaString2) {
		println("Error: t is bigger than s.")
		return
	}
	var positions [1000]int
	k := 0
	for i, j := 0, 0; i < len(dnaString); i++ {
		if dnaString[i] == dnaString2[j] {
			j++
			if j == len(dnaString2) {
				j = 0
				i = i - len(dnaString2) + 1
				positions[k] = i + 1
				k++
			}
		} else {
			j = 0
		}
	}
	for i := 0; i < k; i++ {
		fmt.Printf("%d ", positions[i])
	}
}
