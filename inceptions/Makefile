VOLUME_DIR	:=	/Users/gangjiho/data
DOCKER_COMPOSE	:=	docker-compose
DOCKER_COMPOSE_FILE	:=	./srcs/docker-compose.yml
PROJECT_NAME	:=	Inception
NETWORK_NAME := network-inception

.PHONY:	all
all:
	@mkdir -p $(VOLUME_DIR)/db
	@mkdir -p $(VOLUME_DIR)/wp
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) up --build -d

logs:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) logs


db:
	sudo docker compose -f $(COMPOSEFILE) exec mariadb /bin/bash

.PHONY:	up
up:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) up

.PHONY:	down
down:
	$(DOCKER_COMPOSE) -f $(DOCKER_COMPOSE_FILE) down

.PHONY: clean
clean: down
	docker system prune -f --all # Remove all unused images not just dangling ones

.PHONY: fclean
fclean: clean
	@rm -rf $(VOLUME_DIR)/db
	@rm -rf $(VOLUME_DIR)/wp
	@docker volume rm $$(docker volume ls -q)

.PHONY: re
re: fclean all


