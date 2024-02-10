import { InputContainerProps } from '@/types';

export const userInfo: InputContainerProps[] = [
  {
    name: 'email',
    id: 'email',
    type: 'email',
    required: true,
    placeholder: 'test@example.com',
  },
  {
    name: 'password',
    id: 'password',
    type: 'password',
  },
];

export const userGender = ['male', 'female', 'other'];
