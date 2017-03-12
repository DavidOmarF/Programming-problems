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

func invertString(dnaString []byte) []byte {
	var middle int
	if len(dnaString)%2 == 0 {
		middle = len(dnaString)/2 - 1
	} else {
		middle = (len(dnaString)+1)/2 - 1
	}
	for i := 0; i <= middle; i++ {
		aux := dnaString[i]
		dnaString[i] = dnaString[len(dnaString)-i-1]
		dnaString[len(dnaString)-i-1] = aux
	}
	return dnaString
}

func main() {
	dnaString := []byte(readFile(0))
	for i := 0; i < len(dnaString); i++ {
		if dnaString[i] == 'A' {
			dnaString[i] = 'T'
		} else if dnaString[i] == 'C' {
			dnaString[i] = 'G'
		} else if dnaString[i] == 'G' {
			dnaString[i] = 'C'
		} else if dnaString[i] == 'T' {
			dnaString[i] = 'A'
		}
	}
	fmt.Printf("%s\n", invertString(dnaString))
}
