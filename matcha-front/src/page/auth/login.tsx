import Button from '@/components/Button';
import Form from '@/components/Form';
import InputContainer from '@/components/InputContainer';
import Label from '@/components/Label';
import Input from '@/components/input';
import { userInfo } from '@/data/auth_data';
import { ApiContainers } from '@/provider/ApiContainerProvider';
import React, { useState } from 'react';
import { Link } from 'react-router-dom';

export default function Login() {
  const value = React.useContext(ApiContainers);

  return (
    <Form
      onSubmit={(e) => {
        e.preventDefault();
        const data = new FormData(e.currentTarget);
        const obj: Record<string, FormDataEntryValue> = {};
        for (let [key, value] of data.entries()) {
          obj[key] = value;
        }
        value.call('login', obj);
      }}
    >
      <div>
        <h1>Login</h1>
        <p>Enter your email below to login to your account</p>
      </div>
      <div>
        {userInfo.map((item) => (
          <InputContainer {...item} key={`user_${item.id}`} />
        ))}
        <Button type="submit">Login</Button>
        <Link to="/register">Sign Up</Link>
      </div>
    </Form>
  );
}
