# Quiz Game:
## ${\color{orange}\text{Concept explanation}}$:
Quiz game is importing three code files: two has classes and one contain two data: the quiz's text (statement) and its answer (Boolean)
<br>
<br>`Question` class in `question_model` file is responsible for creating an object that takes two inputs: the text and the answer
<br>`question_data` dictionary array in `question_model` file holds an array of dictionaries each contains two keys: `text` and `answer`
<br>`Quiz` class in `quiz_brain` file is responsible for manipulating an input object from `Question` class which holds both:
<br>`text` and `answer` arrays attributes
<br>
<br>The object from `Quiz` has 3 attributes for: holding index, score and input list.
<br>And 2 methods for: checking whether there is a next question and processing the available question.



