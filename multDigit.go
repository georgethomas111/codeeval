// Multiply digits in a list.
package main

import "fmt"
import "log"
import "bufio"
import "os"

import "strings"
import "strconv"

const (
IPNUM = 2
)

func multList(list1 []int, list2 []int) []int {

     list3 := make([]int, len(list1))
     for index, _ := range list1 {
	list3[index] = list1[index] * list2[index]
     }
     return list3
}

func displayRes(list []int) {
    for _, val := range list {
	fmt.Print(val, " ")
    }
    fmt.Print("\n")
}

func main() {
    file, err := os.Open(os.Args[1])
    if err != nil {
        log.Fatal(err)
    }   
    defer file.Close()
    scanner := bufio.NewScanner(file)
    for scanner.Scan() {
        //'scanner.Text()' represents the test case, do something with it

	splitStr := strings.Split(scanner.Text(), "|")
        list     := make([][]int, IPNUM)

	for i := 0; i < IPNUM; i++ {
            nums := strings.Split(strings.TrimSpace(splitStr[i]), " ")
	    list[i] = make([]int, len(nums))
	    for j := 0; j < len(nums); j++ {
		list[i][j], _ = strconv.Atoi(nums[j])
	    } 
	}	
	list3 := multList(list[0], list[1])
	displayRes(list3)
    }   
}
