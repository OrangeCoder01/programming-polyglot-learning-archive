# Day 17 Learning OOP by making personally-made classes 

class User:# Name Classes with PascalCase case
    def __init__(self, user_id, user_name):
        self.id = user_id
        self.name = user_name
        self.follower_count = 0
        self.following_count = 0
    
    def follow(self, user):
        user.follower_count += 1
        self.following_count += 1
        
        

# Remember: PascalCase, camelCase and snake_case
user_1 = User("001", "Michael")
user_2 = User("651", "Momo")

user_1.follow(user_2)

print(f"user_1 name / ID / number of followers & followings: {user_1.name} / {user_1.id} / {user_1.follower_count} followers / {user_1.following_count} following")
print(f"user_2 name / ID / number of followers & followings: {user_2.name} / {user_2.id} / {user_2.follower_count} followers / {user_2.following_count} following") 