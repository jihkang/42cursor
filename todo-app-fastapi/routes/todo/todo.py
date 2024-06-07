from fastapi import APIRouter, Depends, Body, HTTPException
from database.database import get_db
from database.models.todo import TodoModel as Model
from database.scheme.todo import TodoScheme as Scheme
from sqlalchemy.orm import Session


api_router = APIRouter(prefix="/api/todo", tags=["todo"])


@api_router.get("/")
async def read_all(db: Session = Depends(get_db)):
    print(db.query(Model).all())
    return db.query(Model).all()
    # return "all items will be show"


@api_router.get("/{key}")
async def read_one(key: int, db: Session = Depends(get_db)):
    # print('read_one')
    item = db.query(Model).filter(Model.id == key).first()
    if not item:
        raise HTTPException(status_code=404, detail="Todo not found")
    return item


@api_router.post("/")
async def create_post(data: Scheme = Body(...), db: Session = Depends(get_db)):
    try:
        todo = Model(**data.dict())
        db.add(todo)
        db.commit()
        db.refresh(todo)
        return todo
    except SQLAlchemyError:
        db.rollback()
        raise HTTPException(status_code=500, detail="Could not create todo")


@api_router.delete("/")
async def delete_all():
    return "all items will be deleted"


@api_router.delete("/{key}")
async def delete_one(key):
    return "Not Implemented"


