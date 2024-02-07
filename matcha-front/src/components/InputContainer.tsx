import { InputContainerProps } from '@/types';
import Label from './Label';
import Input from './input';

const InputContainer: React.FC<InputContainerProps> = ({
  type,
  id,
  name,
  required = false,
  placeholder = '',
}) => {
  /*
		<div>
      <Label htmlFor="email">Email</Label>
      <Input name="email" id="email" placeholder="m@example.com" required type="email" />
    </div>
	*/
  return (
    <div>
      <Label htmlFor={name}>{name}</Label>
      <Input name={name} id={id} type={type} required={required} placeholder={placeholder}></Input>
    </div>
  );
};

export default InputContainer;
