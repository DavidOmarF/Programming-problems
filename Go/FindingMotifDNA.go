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
	var pos [1000]int
	k := 0
	for i, j := 0, 0; i < len(dnaString) && j < len(dnaString2); i++ {
		if dnaString[i] == dnaString2[j] {
			if j+1 == len(dnaString2) {
				i = i - j
				pos[k] = i + 1
				j = 0
				k++
			} else {
				j++
			}
		} else {
			if j != 0 {
				i -= j
				j = 0
			}
		}
	}
	for i := 0; i < k; i++ {
		fmt.Printf("%d ", pos[i])
	}
}
