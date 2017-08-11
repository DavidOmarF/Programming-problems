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
	dnaString := []byte(readFile(0))  					// Obtains both DNA Strings, in the form of Byte Array.
	dnaString2 := []byte(readFile(1))
	if len(dnaString) < len(dnaString2) {					// Second DNA String should be shorter (or equal)
		println("Error: t is bigger than s.")				// in order to be a substring of the first one.
		return
	}
	var pos [1000]int							// Still don't know how to dinamically assign 
										// a variable size to an array. I think that 
										// ideally, it should be dnaString - dnaString2
	k := 0									// K is the number of times that dnaString is a subString.
	for i, j := 0, 0; i < len(dnaString) && j < len(dnaString2); i++ {	
	//First, the loop gets sure that i and j are not indexes out of range	
		if dnaString[i] == dnaString2[j] {
		// If index i and j in both strings are equal, proceeds with:
			if j+1 == len(dnaString2) {
			// If j is the last index of dnaString2, it means that is a substring.
				i = i - j
				// Returns i to the original index in where the 'concidence' started.
				pos[k] = i + 1
				// Assigns the position (plus one)* to the array of positions
				j = 0
				// Starts the second string in 0, so it can check another coincidence
				k++ 
			} else {
			// If j is not the last index of dnastring2, it moves to the next one.
				j++
			}
		} else {
		// If index i and j in both strings are not equal, then:
			if j != 0 {
			// If j is not the first index in de second String, returns index i to the value of the first coincidence,
			// and index j to 0
				i -= j
				j = 0
			}
		}
	}
	for i := 0; i < k; i++ {
		fmt.Printf("%d ", pos[i])
	}
}
