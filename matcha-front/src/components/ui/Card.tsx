import styled from 'styled-components';
import React, { ReactNode } from 'react';

interface CardTypes {
  [key: string]: ReactNode | string | undefined;
  width?: string;
  borderRadius?: string;
  children?: ReactNode;
}

export const CardHeader = styled.div<CardTypes>``;
export const CardFooter = styled.div<CardTypes>``;
export const CardBody = styled.div<CardTypes>``;

const CardComponents = styled.div<CardTypes>`
  display: flex;
  flex-direction: column;
  width: ${(props) => props?.width};
  border-radius: ${(props) => props.borderRadius};
  border: 1px solid;
  min-height: 400px;
  min-width: 450px;
  width: fit-content;
  height: fit-content;
  ${CardBody} {
    min-height: 300px;
    height: fit-content;
    padding: 10px 5px 10px 5px;
    border-bottom: 1px solid;
  }
  ${CardFooter} {
    justify-contents: center;
    height: 60px;
    padding: 10px 5px 10px 5px;
  }
`;

const Card: React.FC<CardTypes> = ({ children, ...rest }) => {
  return <CardComponents {...rest}>{children}</CardComponents>;
};

export default Card;
