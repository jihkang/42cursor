import { ReactNode } from 'react';

interface ButtonProps {
  [key: string]: any;
  onClick?: (props: any) => any;
  children?: ReactNode;
  style?: any;
}

const Button: React.FC<ButtonProps> = ({ onClick, children, style }) => {
  return (
    <button onClick={onClick} style={style}>
      {children}
    </button>
  );
};

export default Button;
