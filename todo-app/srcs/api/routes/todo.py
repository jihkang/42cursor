from fastapi import APIRouter, Body
from schemas.todo import TodoScheme

todo_router = APIRouter(prefix="/api/todo", tags=["todo"])

items = [
    {"id": 0, "title": "Todo", "content": "test"},
    {"id": 1, "title": "TodoTest", "content": "test-without database"},
]


@todo_router.get("/")
async def get_todo_all():
    return {
        "status": 200,
        "data": items
    }


@todo_router.post("/")
async def post_todo(todo: TodoScheme):
    t = todo.dict()
    t['id'] = len(items)
    items.append(t)
    return items


@todo_router.put("/{key}")
async def update_todo(key: int):
    return "Not Implements"


@todo_router.delete("/{key}")
async def delete_todo(key: int):
    return "Not Implements"