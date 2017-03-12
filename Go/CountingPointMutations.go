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
	dnaString := []byte(readFile(0))
	dnaString2 := []byte(readFile(1))
	if len(dnaString) != len(dnaString2) {
		println("Error: s and t are not equal length")
		return
	}
	mutations := 0
	for i := 0; i < len(dnaString); i++ {
		if dnaString[i] != dnaString2[i] {
			mutations++
		}
	}
	print(mutations)
}
