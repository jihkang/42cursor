import Button from '@/components/Button';
import Form from '@/components/Form';
import InputContainer from '@/components/InputContainer';
import { userInfo } from '@/data/auth_data';
import { Link } from 'react-router-dom';

const Register = () => {
  return (
    <Form>
      {userInfo.map((item) => (
        <InputContainer {...item} />
      ))}
      <Button type="submit">Sign up</Button>
      <h2>
        Do you have an account?
        <Link to="/login">Login</Link>
      </h2>
    </Form>
  );
};

export default Register;
