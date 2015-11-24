package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"sort"
	"strings"
)

func remove(input string, index int) (output string) {

	prefix := input[:index]
	suffix := input[index+1:]
	outStr := prefix + suffix
	return outStr
}

func display(sliceInter []string) {

	fmt.Println(strings.Join(sliceInter, ","))
}

func Perm(input string) []string {

	var perms = []string{}
	if len(input) == 1 {
		perms = []string{input}
		return perms
	} else {
		for index, _ := range input {
			newStr := remove(input, index)
			newStrPerms := Perm(newStr)
			for _, perm := range newStrPerms {
				perms = append(perms, string(input[index])+perm)
			}
		}
	}
	return perms
}

func main() {

	file, err := os.Open(os.Args[1])
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		perms := Perm(scanner.Text())
		sort.Strings(perms)
		display(perms)
	}
}
