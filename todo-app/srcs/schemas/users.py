from pydantic import BaseModel, EmailStr
from typing import List, Union


class UserEmail(BaseModel):
    email: EmailStr


class UserID(BaseModel):
    id: str


class UserSNS(BaseModel):
    sns: str


class UserLoginSchema(BaseModel):
    scheme: Union[UserID, UserEmail, UserSNS]
    password: str





