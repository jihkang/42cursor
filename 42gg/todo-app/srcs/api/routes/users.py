from fastapi import APIRouter
from schemas.users import UserLoginSchema, UserEmail, UserID, UserSNS

users_router = APIRouter(prefix="/api/users", tags=["users"])


@users_router.post("/", response_model=UserLoginSchema)
async def get_users(user: UserLoginSchema):
    """ NOT IMPLEMENT YET"""
    print(user)
    if isinstance(user.scheme, UserID):
        return {"message": f"User info for ID: {user.scheme.id}"}
    elif isinstance(user.scheme, UserEmail):
        return {"message": f"User info for Email: {user.scheme.email}"}
    elif isinstance(user.scheme, UserSNS):
        return {"message": f"User info for SNS: {user.scheme.sns}"}
    else:
        raise HTTPException(status_code=400, detail="Invalid user type")




