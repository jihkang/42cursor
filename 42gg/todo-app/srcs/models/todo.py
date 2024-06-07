from typing import Optional
from sqlalchemy.ext.declarative import declarative_base

base = declarative_base()


class Todo(base):
    __tablename__ = "todo"

    id = Column(Integer, primary_key=True, index=True)
    title = Column(String, nullable=False)
    content = Column(String, nullable=False)


   def __repr__(self):
       return f"<Todo {self.id}>"

