from fastapi import FastAPI

app = FastAPI()
# FastAPI -> class , app -> object created from that class
@app.get("/")
def Home():
    return {'message':"Hello from the Fast api "}

# .get() -> respond to http get requests .
# uvicorn main:app --reload [restart automatically when you change code]

