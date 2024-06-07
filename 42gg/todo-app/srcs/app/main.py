from fastapi import FastAPI
from api.routes.todo import todo_router
from api.routes.users import users_router

app = FastAPI()
app.include_router(todo_router)
app.include_router(users_router)


@app.get("/")
async def index():
    return {
        "status" : "todo api is running"
    }

