// For problem background, go to:
// http://rosalind.info/problems/hamm/

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
	// Gets sure that both strings are the same lenght
		println("Error: s and t are not equal length")
		return
	}
	mutations := 0
	// Starts number of mutations in 0
	for i := 0; i < len(dnaString); i++ {
	// Counts mutations. Easy.
		if dnaString[i] != dnaString2[i] {
			mutations++
		}
	}
	print(mutations)
}
