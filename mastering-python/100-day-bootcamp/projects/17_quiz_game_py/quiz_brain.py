def user_choice_validation(valid_pool_choices):
    user_choice = input("Your choice: ")
    while user_choice not in valid_pool_choices:
        user_choice = input(f"Input {user_choice} is not found in {valid_pool_choices}, please enter again: ")
    return user_choice


class QuizBrain:
    def __init__(self, q_list):
        self.question_number = 0
        self.total_q = 0
        self.score = 0
        self.question_list = q_list
    
    def are_there_still_questions(self):
        return self.question_number < len(self.question_list.statement)
    
    def next_question(self):
        current_question = self.question_list
        print(f"Q.{self.question_number + 1}: {current_question.statement[self.question_number]} (True/False)? ")
        
        add_on_str = ""
        if user_choice_validation(["True", "False"]) != current_question.answer[self.question_number]:
            add_on_str += "in"
        else:
            self.score += 1
            
        print(f"{add_on_str}correct! you got {self.score}/{self.question_number + 1}")
        self.question_number += 1
            
        