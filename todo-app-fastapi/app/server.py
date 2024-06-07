from fastapi import FastAPI
from routes.todo.todo import api_router as todo_api
from routes.test.test import api_router as test_api


def init_routes(app_: FastAPI):
    app_.include_router(todo_api)
    app_.include_router(test_api)


def create_app() -> FastAPI:
    app_ = FastAPI()
    init_routes(app_)
    return app_


app = create_app()
