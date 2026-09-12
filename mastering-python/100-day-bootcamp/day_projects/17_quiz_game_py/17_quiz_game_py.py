import data, question_model, quiz_brain

texts = []
answers = []

for question in data.question_data:
    texts.append(question["text"])
    answers.append(question["answer"])
    
question_bank = question_model.Question(texts, answers)
quiz = quiz_brain.QuizBrain(question_bank)

while quiz.are_there_still_questions():
    quiz.next_question()

print("\nYou completed the quiz!")
print(f"You got {quiz.score} correct out of total {quiz.question_number} questions")  

    
    
    
    