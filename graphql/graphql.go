package main

import (
	lc "github.com/WindomZ/leetcode-graphql"

	"fmt"
	"log"
	"os"
)

type Question struct {
	ID         string
	Title      string
	Difficulty string
}

func main() {
	q_base := lc.BaseQuestion{}
	title_slug := "minimum-size-subarray-sum"
	q_base.Do(title_slug)
	q := Question{q_base.QuestionID, q_base.QuestionTitle, q_base.Difficulty}
	qOutput(q, q_base)
}

func qOutput(q Question, q_base lc.BaseQuestion) {
	fmt.Printf("%+v", q)
	path_content := "content_" + q.ID + ".md"
	qFile(path_content, q_base.Content)
}

func qFile(path string, content string) {
	err := os.WriteFile(path, []byte(content), 0666)
	if err != nil {
		log.Fatal(err)
	}
}
