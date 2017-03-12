package main

import (
	"bufio"
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
	dnaString := readFile(0)
	for i := 0; i < len(dnaString); i++ {
		if dnaString[i:i+1] == "T" {
			dnaString[i] = 85
		}
	}
}
