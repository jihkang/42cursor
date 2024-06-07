from fastapi import APIRouter


api_router = APIRouter(prefix="/test", tags=["test"])


@api_router.get("/")
async def index():
    return "hi"


@api_router.post("/")
async def add(request):
    print(request)
    return {
        "status": 200,
        "text": "hello Test code"
    }
