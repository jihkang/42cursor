import styled from 'styled-components';
import Card, { CardBody, CardFooter } from './Card';
import { useState } from 'react';

const HeaderContainer = styled.header`
  min-height: 200px;
`;

const HeaderTabContainer = styled.div`
  position: sticky;
  top: 0;
  display: flex;
  height: 100%;
  flex-direction: row;
  background-color: #f5f5f5;
  justify-content: center;
  text-align: center;
`;

const HeaderTab = styled.div`
  width: calc(50% - 2px);
  height: 40px;
  z-index: 100;
  &:first-child {
    border-right: 1px solid;
  }
`;

const test = [
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
  { user: 'test', title: 'test1' },
];

const test2 = [
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
  { user: 'test', title: 'test2' },
];

const Header = () => {
  /**
   * will be replaced with actual data given by the backend
   * and will be passed from parent components
   */

  const [tab, setTab] = useState(false);

  return (
    <HeaderContainer>
      <HeaderTabContainer>
        <HeaderTab onClick={() => setTab(false)}>first</HeaderTab>
        <HeaderTab onClick={() => setTab(true)}>second</HeaderTab>
      </HeaderTabContainer>
      <div>
        {/**
         * under code will be changed by backend api data
         */}
        {!tab
          ? test.map((item, ind) => (
              <Card key={ind}>
                <CardBody>{item.user}</CardBody>
                <CardFooter>{item.title}</CardFooter>
              </Card>
            ))
          : test2.map((item, ind) => (
              <Card key={ind}>
                <CardBody>{item.user}</CardBody>
                <CardFooter>{item.title}</CardFooter>
              </Card>
            ))}
      </div>
    </HeaderContainer>
  );
};

export default Header;
