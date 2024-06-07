from sqlalchemy.ext.compiler import compiles
from sqlalchemy.orm import sessionmaker
from sqlalchemy import create_engine


DATABASE_URL = "sqlite:///test.db"
engine = create_engine(DATABASE_URL, echo=True)
session_local = sessionmaker(
    autocommit=False,
    autoflush=False,
    bind=engine
)


def get_db():
    db = session_local()
    try:
        yield db
    finally:
        db.close()
