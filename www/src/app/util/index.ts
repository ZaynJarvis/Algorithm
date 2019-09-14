// tslint:disable
export const generateUUID = () => {
  let d = new Date().getTime();
  return 'xxxx-4xxx-yxxx'.replace(/[xy]/g, c => {
    const r = (d + Math.random() * 16) % 16 | 0;
    d = Math.floor(d / 16);
    return (c === 'x' ? r : (r & 0x3) | 0x8).toString(16);
  });
};
