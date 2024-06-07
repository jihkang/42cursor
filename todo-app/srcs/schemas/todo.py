from pydantic import BaseModel
from typing import List


class TodoScheme(BaseModel):
    title: str
    content: str


class TodoResponse(BaseModel):
    todos: List[TodoScheme]

    class Config:
        orm_mode = True
