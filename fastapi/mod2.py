# Path vs Query Parameters
'''
When building APIs, we often need to receive data from the user.
FastAPI gives two major ways:
- Path parameters → data inside the URL path
- Query parameters → data after a ? in URL
'''

from fastapi import FastAPI

app = FastAPI()

# path parameter: Path params are used to identify something unique.
@app.get("/items/{item_ids}")
def get_item(item_ids: str):
    return {"Item Id":item_ids}

''' Behind the scene its working: 
- User opens URL:
 /items/apple

- FastAPI matches route:
 "/items/{item_ids}"

- It extracts item_ids = "apple"

- It checks function signature:
 item_ids: str

- Converts the URL value into a string (already string)
 Calls your function:
 get_item("apple")

- Your function returns a dictionary

- FastAPI converts dictionary → JSON

- Sends the JSON response to the browser- 
'''

'''
(item_id : int) tells fast api:
- item_id must be an integer
- if someone sends a string , fast api automatically returns an error .
'''

# query parameter
'''
Query params represent optional information, usually for:
Filtering, Searching, Sorting, Pagination ..
They appear after a ? in URL:
/products?category=mobile
/search?keyword=python
/users?active=true&limit=20
'''
@app.get("/search")
def search(w: str="all"):
    return {"You searched for: ":w}

# http://127.0.0.1:8000/search?w=fastapi
# output : You searched for :fastapi