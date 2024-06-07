"""second

Revision ID: 01ab64474f34
Revises: 0255c464f23e
Create Date: 2024-06-07 20:33:35.959698

"""
from typing import Sequence, Union

from alembic import op
import sqlalchemy as sa


# revision identifiers, used by Alembic.
revision: str = '01ab64474f34'
down_revision: Union[str, None] = '0255c464f23e'
branch_labels: Union[str, Sequence[str], None] = None
depends_on: Union[str, Sequence[str], None] = None


def upgrade() -> None:
    pass


def downgrade() -> None:
    pass
