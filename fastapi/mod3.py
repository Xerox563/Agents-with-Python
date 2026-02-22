from fastapi import FastAPI

from models.student import Student

app = FastAPI()

@app.post("/students")
def create_student(student:Student):
    return {
        "message":"Student Profile Created",
        "data_recieved":student
    }

# Behind the scenes:
'''
➤ Step 1: User sends JSON body
{
  "name": "John Doe",
  "age": 18,
  "grade": "12th",
  "email": "john@example.com"
}

➤ Step 2: FastAPI reads your function
def create_student(student: Student):
 - expects JSON
 - validates it using student model
 - JSON - Python object

➤ Step 3: Pydantic Validates Everything
 - Is name a string?
 - Is age an integer?
 - Is grade a string?

➤ Step 4: FastAPI creates a Python object
 - inside the object you can access using the student.name,student.age etc

➤ Step 5: You return something
FastAPI automatically converts your return value to JSON. 

'''