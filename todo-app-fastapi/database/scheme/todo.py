from pydantic import BaseModel


class TodoScheme(BaseModel):
    title: str
    content: str

