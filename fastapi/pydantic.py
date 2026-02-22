from pydantic import BaseModel
from typing import Optional

class Student(BaseModel):
    name:str
    age:int
    grade:Optional[str] = None

# lets say grade is optional means wheather the user can send that or can be the case that it dont send anything .

# automatic type conversion : rooms take lets float but got string then string is typecasted into float.
class Hostel(BaseModel):
    name:str = "Jai Bharat Hostel" # default value
    rooms:int
# Pydantic handles automatically : Validation Errors (FastAPI Gives Automatically)
'''
Example model:
class Student(BaseModel):
    name: str
    age: int

User sends:
{
  "name": "Amit",
  "age": "twenty"
}

FastAPI response:
{
  "detail": [
    {
      "loc": ["body", "age"],
      "msg": "value is not a valid integer",
      "type": "type_error.integer"
    }
  ]
}
'''

# list of models:
class Hobby(BaseModel):
    name:str
    difficulty:int

class CollegeStudent(BaseModel):
    name:str
    hobbies: list[Hobby]

'''
This handles:
{
  "name":"Amit Gangwar",
  "hobbies":[
     {"name":"F1 racing","difficulty:3},
     {"name":"Carx Street","difficulty:4}
   ]
}
'''    

    