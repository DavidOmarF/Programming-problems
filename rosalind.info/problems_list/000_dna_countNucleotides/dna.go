// For problem background, go to:
// http://rosalind.info/problems/dna/

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
	dnaString := []byte(readFile(0))			// Converts a string to an array of bytes and assigns
	t := [4]int						// Each position of int array t corresponding to A, C, G, and T
	for i := 0; i < len(dnaString); i++ {			
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
	fmt.Println(t)						// Prints all values on t
}
