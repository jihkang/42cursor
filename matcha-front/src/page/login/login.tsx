import Button from '@/components/Button';
import Form from '@/components/Form';
import Label from '@/components/Label';
import Input from '@/components/input';
import { ApiInstance } from '@/types';
import { ApiCall } from '@/utils/api';
import { ApiContainers } from '@/provider/ApiContainerProvider';
import React from 'react';

export default function Login() {
  const value = React.useContext(ApiContainers);

  return (
    <Form
      onSubmit={(e) => {
        e.preventDefault();
        const data = new FormData(e.currentTarget);
        console.log(
          value.call('login', { email: data.get('email'), password: data.get('password') }),
        );
      }}
    >
      <div>
        <h1>Login</h1>
        <p>Enter your email below to login to your account</p>
      </div>
      <div>
        <div>
          <Label htmlFor="email">Email</Label>
          <Input name="email" id="email" placeholder="m@example.com" required type="email" />
        </div>
        <div>
          <Label htmlFor="password">Password</Label>
          <Input name="password" id="password" required type="password" />
        </div>
        <Button type="submit">Login</Button>
        <Button>Login with GitHub</Button>
      </div>
    </Form>
  );
}
