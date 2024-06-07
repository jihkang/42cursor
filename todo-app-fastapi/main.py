import uvicorn 


def main():
    uvicorn.run(
        app='app.server:app'
    )


if __name__ == "__main__":
    main()
