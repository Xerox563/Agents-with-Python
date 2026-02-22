# FastAPI is a python web framework used to build
# - APIS , Backeneds, Microservices, Server side logic for apps .
'''
- Fast to write : code is short and simple
- Fast to run : uses modern pyhton features (async) to handle requests at once.
'''

# Why FastAPI Fast ?
'''
- Fast api is fast mainly because it uses asynchronous programming , which allows python to handle many requst at the same time .
What is Synchronous (sync)? [Django, flask]
- Sync = one task at a time, in order.
- You have one waiter in a restaurant.
- He takes an order → waits for food → serves → then takes next order.
- A request comes → Execute → Finish → Next request

What is Asynchronous (async)?
- Async = handle many tasks at the same time, without waiting.
- A waiter takes an order
→ while food is being prepared, he takes other orders
→ when food is ready, he serves it.
- He doesn’t wait idle.

- A request comes → Start task → While waiting, do another task

Event Loop: [Due to this fast api is very fast]
Python has an event loop that runs async tasks.
Think of it as:
A manager that keeps track of multiple tasks and switches between them so nothing sits idle.

:: Why async is important for APIs?
Because APIs often wait:
waiting for database
waiting for API calls
waiting for file operations
While waiting, sync code does nothing.
But async code starts another task during waiting time.
This massively improves performance.
'''

# Why fast api is fast ?
'''
1. ASGI Server(Uvicorn) : Heart of the Fast api
: Asynchronous Server Gateway Interface [supports async python]
old tech : WSGI : web server Gateway Interface [does not supports sync code]

| WSGI (old)            | ASGI (new)              |
| --------------------- | ----------------------- |
| One request at a time | Many at the same time   |
| Can't use async       | Fully supports async    |
| Slower under load     | Super fast and scalable |

- Uvicorn is simply the engine that runs the fast api
Think of FastAPI as a car and Uvicorn as the engine inside it.

2. Starlette: The super fast core
Fast api is actually built on top of starlette.
- A very lightweight , very fast framework that handles routing, request,responses, middleware, bg tasks,websockets.
Fast api adds:
- data validation , automatics docs etc.

3. Pydantic : Blazing Fast Data Validation
When you send data to an API , Fastapi :
- checks you sent correct types
- checks required fields
- converts types automatically
- gives clear error message
Traditionally you write LOTS of code for validation.
Pydantic handles validation automatically using Python type hints:

- Behind the scenes Pydantic is written in optimized C code under the hood .

4. Async I/O — The Real Speed Booster
- Async I/O lets your app do other work while waiting for:
database response
API calls
file operations
long calculations

- With async, your API can handle:
1000 users
5000 users
at the same time, depending on server power.
'''

'''
Fast api : Framework we write code with.
Uvicorn : Server that runs our Fast api code

:: We need Uvicorn beacuse Fast api uses ASGI and uvicorn is one os the fastest ASGI servers.
:: uvicorn main:app
 -- uvicorn starts
 -- It loads your FastAPI app
 -- It begins accepting requests
 -- It routes them to your API functions
'''

# Package : A package is a collection of Python code someone wrote so you can reuse it.
# pip : Pythons installer

'''
# Venv
A virtual environment is a self-contained folder that has:
Its own Python version
Its own installed packages
Its own dependencies
This means anything you install inside a venv won’t affect your system Python or other projects.

Why is venv important?

Imagine you have two projects:
Project A needs Django 4
Project B needs Django 3

Without venv, you can’t install both versions globally.
With venv, each project gets separate dependencies, so no conflicts happen.

Command:
- python -m venv venv  # creation
- source venv/bin/activate  # activation
- deactivate  # deactivation
'''
